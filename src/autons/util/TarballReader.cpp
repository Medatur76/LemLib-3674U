#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

PathReader::PathReader(const asset& path) {
    const std::string tarball_str = std::string(reinterpret_cast<const char*>(path.buf), path.size);
    std::string debug_str = "";

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
                std::string path_name = currentLine.substr(19);
                paths.push_back(path_name);
                debug_str += path_name + " ";
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
    
    pros::lcd::set_text(5, debug_str);
}

asset& PathReader::operator[](const char* path_name) {
    for (size_t i = 0; i < paths.size(); i++) {
        if (paths[i] == path_name) { return assets[i]; }
    }

    pros::lcd::set_text(1, std::string("Path not found: ") + path_name);
    static asset empty = {nullptr, 0};
    return empty;
}