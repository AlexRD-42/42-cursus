/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:17:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/07 12:15:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// tab = 9
// receives a char and converts it to hex


// void print_hex(char *arr, int )
// {
//     char hex[17] = "0123456789abcdef";
// }

// void    *ft_print_memory(void *addr, unsigned int size)
// {
//     int i;
// }

int main() {
    int a = 10;
    void *addr = &a;
    char hex[17] = "0123456789abcdef";

    unsigned char *ptr = (unsigned char *)&addr;  // Treat the address of 'a' as bytes

    // Print "0x" prefix
    write(1, "0x", 2);

    // Assuming a 64-bit system (8 bytes for a pointer)
    for (int i = sizeof(void *) - 1; i >= 0; i--) {
        unsigned char byte = ptr[i];
        // Print each byte as two hex characters without bit manipulation
        write(1, &hex[byte / 16], 1);  // High nibble as a character
        write(1, &hex[byte % 16], 1);  // Low nibble as a character
    }

    return 0;
}