#pragma once

#include <iostream>
#include <sstream> 
#include <ctime>
#include "sha256.h"

namespace coin { namespace block {

    class Block 
    {
        public:
            int index;
            std::string hash;
            std::string prev_hash;
            std::string timestamp;
            std::string data;

        public:
            Block(int index, std::string hash, std::string prev_hash, std::string timestamp, std::string data);
            ~Block();
            std::string calculate_hash(int index, std::string prev_hash, std::string timestamp, std::string data) const;
            std::string calculate_hash_for_block(Block& block) const;
            void populate_block(std::string data, Block& new_block, Block& prev_block);
            bool is_valid_new_block(Block& new_block, Block& prev_block) const;
    };

}}