#include <iostream>
#include <bitset>

int main()
{
    int num = 0b1011001110001111; // Example 16-bit number

    // Extract bits 1-4 (leftmost)
    // int first4 = (num >> 12) & 0xF;
    // int second4 = (num >> 8) & 0xF;

    int first4 = (num >> 8) & 0xF;
    int second4 = (num >> 4) & 0xF;

    // uint8_t outer_page_number = (logical_address >> 8) & 0xF;
    // uint8_t page_number = (logical_address >> 4) & 0xF;

    // Print results
    std::cout << "Original: " << std::bitset<16>(num) << std::endl;
    std::cout << "First 4 bits (1-4): " << std::bitset<4>(first4) << " (" << first4 << ")" << std::endl;
    std::cout << "Second 4 bits (5-8): " << std::bitset<4>(second4) << " (" << second4 << ")" << std::endl;

    return 0;
}
