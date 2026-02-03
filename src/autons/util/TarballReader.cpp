#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

PathReader::PathReader(const asset& path) {
    const std::string tarball_str = std::string(reinterpret_cast<const char*>(path.buf), path.size);

    size_t pos = 0, d_pos = 0, s_pos = 0;

    bool recordingPath = false;

    while ((d_pos = tarball_str.find('\n', pos)) != std::string::npos) {
        std::string currentLine = tarball_str.substr(pos, d_pos - pos);

        if (currentLine.starts_with('#')) {
            if (recordingPath) {
                assets.push_back({path.buf + s_pos, d_pos - s_pos});
            }
            if (currentLine.starts_with("#PATH-POINTS-START")) {
                recordingPath = true;
                paths.push_back(currentLine.substr(19));
                s_pos = d_pos + 1;
            } else recordingPath = false;
        }

        pos = d_pos + 1;
    }

    if (recordingPath) {
        std::string last_line = tarball_str.substr(pos);
        std::size_t path_content_end = last_line.starts_with("#") ? pos : path.size;

        // commit the path
        assets.push_back({path.buf + s_pos, path_content_end - s_pos});
    }
}

asset& PathReader::operator[](const char* path_name) {
    for (size_t i = 0; i < paths.size(); i++) {
        if (paths[i] == path_name) { return assets[i]; }
    }

    lemlib::infoSink()->error("Path not found: {}", path_name);
    static asset empty = {nullptr, 0};
    return empty;
}