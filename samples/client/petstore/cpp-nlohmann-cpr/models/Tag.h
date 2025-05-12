#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>

struct Tag {
    std::optional<long> id;
    std::optional<std::string> name;
};

//nlohmann gaming
inline void to_json(nlohmann::json &j, const Tag &o) {
            if(o.id.has_value()) j[ "id" ] = o.id.value();
            if(o.name.has_value()) j[ "name" ] = o.name.value();
}

inline void from_json(const nlohmann::json &j, const Tag &o) {
            if(j.contains("id")) j.at("id").get_to(o.id);
            if(j.contains("name")) j.at("name").get_to(o.name);
}

