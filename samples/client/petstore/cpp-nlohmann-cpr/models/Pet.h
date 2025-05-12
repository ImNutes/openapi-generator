#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>

struct Pet {
    std::optional<long> id;
    std::optional<std::shared_ptr<Category>> category;
    std::string name;
    std::vector<std::string> photoUrls;
    std::optional<std::vector<std::shared_ptr<Tag>>> tags;
    std::optional<std::string> status;
};

//nlohmann gaming
inline void to_json(nlohmann::json &j, const Pet &o) {
    j = nlohmann::json{
                {"name", o.name },
                {"photoUrls", o.photoUrls },
    };
            if(o.id.has_value()) j[ "id" ] = o.id.value();
            if(o.category.has_value()) j[ "category" ] = o.category.value();
            if(o.tags.has_value()) j[ "tags" ] = o.tags.value();
            if(o.status.has_value()) j[ "status" ] = o.status.value();
}

inline void from_json(const nlohmann::json &j, const Pet &o) {
            if(j.contains("id")) j.at("id").get_to(o.id);
            if(j.contains("category")) j.at("category").get_to(o.category);
            j.at("name").get_to(o.name);
            j.at("photoUrls").get_to(o.photoUrls);
            if(j.contains("tags")) j.at("tags").get_to(o.tags);
            if(j.contains("status")) j.at("status").get_to(o.status);
}

