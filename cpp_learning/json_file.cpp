#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

// g++ filename -o runable_name;
// ./runable_name


#if 0



// write file
int main() {

    
    Json::Value jsonData;
    // 键值对
    jsonData["name"] = "Alice";
    jsonData["age"] = 30;
    jsonData["height"] = 1.75;

    Json::Value hobbiesJson;
    hobbiesJson.append("Reading");
    hobbiesJson.append("Swimming");
    hobbiesJson.append("Coding");
    jsonData["hobbies"] = hobbiesJson;

    // Serialize JSON data to a string
    Json::StreamWriterBuilder writer;
    const std::string jsonString = Json::writeString(writer, jsonData);

    // Write JSON string to a file
    std::ofstream outFile("data.json");
    if (!outFile) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return 1;
    }
    outFile << jsonString;
    outFile.close();

    return 0;
}

#endif

// read file
#if 1
int main() {
    std::ifstream inFile("data.json");
    if (!inFile.is_open()) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return 1;
    }

    Json::CharReaderBuilder reader;
    Json::Value jsonData;
    std::string errs;
    if (!Json::parseFromStream(reader, inFile, &jsonData, &errs)) {
        std::cerr << "Error parsing JSON: " << errs << std::endl;
        return 1;
    }

    inFile.close();

    // Access JSON data
    std::string name = jsonData["name"].asString();
    int age = jsonData["age"].asInt();
    double height = jsonData["height"].asDouble();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "size: " << jsonData.size() << std::endl;

    Json::Value hobbiesJson = jsonData["hobbies"];
    for (const Json::Value& hobby : hobbiesJson) {
        std::cout << "Hobby: " << hobby.asString() << std::endl;
    }

    return 0;
}


#endif

#if 0

int main(){

    Json::Value Template;
    Json::Value T_sub;
    // T_sub.reserve(5);
    for(int i =0; i<5;i++){
        // std::string T_name = "T_" + std::to_string(i);
        T_sub["noise"] = true;
        T_sub["x"] = 0.2;



        Json::Value cghDes;
        cghDes.append(0.1);
        cghDes.append(0.2);
        cghDes.append(0.3);

        T_sub["cghDes"] = cghDes;
        Template["template_"+std::to_string(i+1)] = T_sub;

    }
    // Serialize JSON data to a string
    Json::StreamWriterBuilder writer;
    const std::string jsonString = Json::writeString(writer, Template);

    // Write JSON string to a file
    std::ofstream outFile("data_test.json");
    if (!outFile) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return 1;
    }
    outFile << jsonString;
    outFile.close();

}
#endif


//read 
#if 0

int main(){

    std::ifstream inFile("data_test.json");
    if (!inFile.is_open()) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return 1;
    }

    Json::CharReaderBuilder reader;
    Json::Value temp_from_json;
    // std::vector<Templ> temp_from_json; //after filtering 
    std::string errs;
    if (!Json::parseFromStream(reader, inFile, &temp_from_json, &errs)) {
        std::cerr << "Error parsing JSON: " << errs << std::endl;
        return 1;
    }

    inFile.close();

    // Access JSON data

    std::string name = temp_from_json["name"].asString();
    int age = temp_from_json["age"].asInt();
    double height = temp_from_json["height"].asDouble();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;

    Json::Value hobbiesJson = temp_from_json["hobbies"];
    for (const Json::Value& hobby : hobbiesJson) {
        std::cout << "Hobby: " << hobby.asString() << std::endl;
    }

    return 0;

}
#endif