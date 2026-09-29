#pragma once
#include <cstdint>
#include <cstdio>
#include <string>

enum class OpType : uint8_t{
    Set = 1,
    Del = 2
};

class WAL{
    public:
    bool open(const std::string& path);
    void close();

    void append_set(const std::string& key, const std::string& value);
    void append_del(const std::string& key);

    private:
        FILE* file_ = nullptr;

        void write_record(OpType op, const std::string& key, const std::string& value);
};