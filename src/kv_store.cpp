#include "kv_store.hpp"

void KVStore::set(const std::string& key, const std::string& value){
    data_[key] = value;
}

std::optional<std::string> KVStore::get(const std::string& key) const {
    auto it = data_.find(key);
    if (it == data_.end()){
        return std::nullopt;
    }
    return it -> second;
}

std::size_t KVStore::size() const{
    return data_.size();
}

bool KVStore::del(const std::string& key){
    return data_.erase(key);
    }
