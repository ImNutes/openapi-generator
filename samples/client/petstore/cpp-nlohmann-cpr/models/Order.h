#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>

struct Order {
    std::optional<long> id;
    std::optional<long> petId;
    std::optional<int> quantity;
    std::optional<std::string> shipDate;
    std::optional<std::string> status;
    std::optional<bool> complete;
};

//nlohmann gaming
inline void to_json(nlohmann::json &j, const Order &o) {
            if(o.id.has_value()) j[ "id" ] = o.id.value();
            if(o.petId.has_value()) j[ "petId" ] = o.petId.value();
            if(o.quantity.has_value()) j[ "quantity" ] = o.quantity.value();
            if(o.shipDate.has_value()) j[ "shipDate" ] = o.shipDate.value();
            if(o.status.has_value()) j[ "status" ] = o.status.value();
            if(o.complete.has_value()) j[ "complete" ] = o.complete.value();
}

inline void from_json(const nlohmann::json &j, const Order &o) {
            if(j.contains("id")) j.at("id").get_to(o.id);
            if(j.contains("petId")) j.at("petId").get_to(o.petId);
            if(j.contains("quantity")) j.at("quantity").get_to(o.quantity);
            if(j.contains("shipDate")) j.at("shipDate").get_to(o.shipDate);
            if(j.contains("status")) j.at("status").get_to(o.status);
            if(j.contains("complete")) j.at("complete").get_to(o.complete);
}

