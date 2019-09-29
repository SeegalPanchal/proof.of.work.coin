#include "block.h"

namespace coin { namespace block {

    Block::Block(int index, std::string hash, std::string prev_hash, std::string timestamp, std::string data)
    {
        this->index = index;
        this->hash = hash;
        this->prev_hash = prev_hash;
        this->timestamp = timestamp;
        this->data = data;
    }

    Block::~Block()
    {
        return;
    }

    std::string Block::calculate_hash(int index, std::string prev_hash, std::string timestamp, std::string data) const
    {
        std::string to_hash;
        std::stringstream ss; 
        // convert index to string and append
        std::string ind; ss << index; ss >> ind;
        to_hash.append(ind);
        to_hash.append(prev_hash);
        to_hash.append(timestamp);
        to_hash.append(data);
        // return the hash
        SHA256 sha256;
        return sha256(to_hash);
    }

    std::string Block::calculate_hash_for_block(Block& block) const
    {
        std::string to_hash;
        std::stringstream ss;
        // convert index to string
        std::string ind; ss << block.index; ss >> ind;
        to_hash.append(ind);
        to_hash.append(block.prev_hash);
        to_hash.append(block.timestamp);
        to_hash.append(block.data);
        // return the hash
        SHA256 sha256;
        return sha256(to_hash);
    }

    void Block::populate_block(std::string data, Block& new_block, Block& prev_block)
    {
        new_block.index = prev_block.index + 1;
        new_block.prev_hash = calculate_hash_for_block(prev_block);
        // current date/time UTC
        time_t now = time(0); 
        std::string dt = ctime(&now);
        tm *gmtm = gmtime(&now);
        dt = asctime(gmtm);
        new_block.timestamp = dt;
        new_block.data = data;
        new_block.hash = calculate_hash(new_block.index, new_block.prev_hash, new_block.timestamp, new_block.data);
        return;
    }

    bool Block::is_valid_new_block(Block& new_block, Block& prev_block) const
    {
        if (prev_block.index + 1 != new_block.index) {
            std::cout << "Invalid index." << std::endl;
            return false;
        } else if (prev_block.hash != new_block.prev_hash) {
            std::cout << "Invalid previous hash." << std::endl;
            return false;
        } else if (calculate_hash_for_block(new_block) != new_block.hash) {
            std::cout << "Invalid hash." << std::endl;
            return false;
        }
        return true;
    }

}}