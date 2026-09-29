#include "wal.hpp"
#include <io.h>

bool WAL::open(const std::string& path){
    file_ = fopen(path.c_str(), "ab"); // append binary
    return file_ != nullptr;
}

void  WAL::close(){
    if (file_){
        fclose(file_);
        file_ = nullptr;
    }
}

void WAL::append_set(const std::string& key, const std::string& value){
    write_record(OpType::Set, key, value);
}

void WAL::append_del(const std::string& key){
    write_record(OpType::Del, key, "");
}

void WAL::write_record(OpType op, const std::string& key, const std::string& value){
    fwrite(&op, sizeof(op), 1, file_); 
    uint32_t key_len = static_cast<uint32_t>(key.size());
    fwrite(&key_len, sizeof(key_len), 1, file_);
    fwrite(key.data(), 1, key.size(), file_);
    uint32_t value_len = static_cast<uint32_t>(value.size());
    fwrite(&value_len, sizeof(value_len), 1, file_);
    fwrite(value.data(),1 , value.size(), file_);

    fflush(file_);
    _commit(_fileno(file_));
}