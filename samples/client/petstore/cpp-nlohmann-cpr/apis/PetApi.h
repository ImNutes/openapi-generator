#pragma once


class PetApiApi {
public:
    explicit PetApiApi(const std::string& baseUrl) : baseUrl{baseUrl} {}

        // Add a new pet to the store
        // 
        std::shared_ptr<Pet> addPet(std::shared_ptr<Pet> pet) {
            std::string url = baseUrl + "/pet";
            auto response = cpr::POST(cpr::Url{url});

            nlohmann::json j = pet;

            auto response = cpr::POST(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<Pet>>();
        }
        // Deletes a pet
        // 
         deletePet(long petId, std::string apiKey) {
            std::string url = baseUrl + "/pet/{petId}";
            url = std::regex_replace(url, std::regex("\\{\\{?petId\\}\\}"), std::to_string(petId));
            auto response = cpr::DELETE(cpr::Url{url});


            auto response = cpr::DELETE(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Finds Pets by status
        // Multiple status values can be provided with comma separated strings
        std::vector<std::shared_ptr<Pet>> findPetsByStatus(std::vector<std::string> status) {
            std::string url = baseUrl + "/pet/findByStatus";
            std::string query;
            query += "status=" + cpr::util::urlEncode(status);
            url += "?" + query;
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::vector<std::shared_ptr<Pet>>>();
        }
        // Finds Pets by tags
        // Multiple tags can be provided with comma separated strings. Use tag1, tag2, tag3 for testing.
        std::vector<std::shared_ptr<Pet>> findPetsByTags(std::vector<std::string> tags) {
            std::string url = baseUrl + "/pet/findByTags";
            std::string query;
            query += "tags=" + cpr::util::urlEncode(tags);
            url += "?" + query;
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::vector<std::shared_ptr<Pet>>>();
        }
        // Find pet by ID
        // Returns a single pet
        std::shared_ptr<Pet> getPetById(long petId) {
            std::string url = baseUrl + "/pet/{petId}";
            url = std::regex_replace(url, std::regex("\\{\\{?petId\\}\\}"), std::to_string(petId));
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<Pet>>();
        }
        // Update an existing pet
        // 
        std::shared_ptr<Pet> updatePet(std::shared_ptr<Pet> pet) {
            std::string url = baseUrl + "/pet";
            auto response = cpr::PUT(cpr::Url{url});

            nlohmann::json j = pet;

            auto response = cpr::PUT(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<Pet>>();
        }
        // Updates a pet in the store with form data
        // 
         updatePetWithForm(long petId, std::string name, std::string status) {
            std::string url = baseUrl + "/pet/{petId}";
            url = std::regex_replace(url, std::regex("\\{\\{?petId\\}\\}"), std::to_string(petId));
            auto response = cpr::POST(cpr::Url{url});


            auto response = cpr::POST(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // uploads an image
        // 
        std::shared_ptr<ApiResponse> uploadFile(long petId, std::string additionalMetadata, std::shared_ptr<file> file) {
            std::string url = baseUrl + "/pet/{petId}/uploadImage";
            url = std::regex_replace(url, std::regex("\\{\\{?petId\\}\\}"), std::to_string(petId));
            auto response = cpr::POST(cpr::Url{url});


            auto response = cpr::POST(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<ApiResponse>>();
        }
private:
    std::string baseUrl;
}
