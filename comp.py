"""
ADD   RA, RB       1000xxxx
SHR   RA, RB       1001xxxx
SHL   RA, RB       1010xxxx
NOT   RA, RB       1011xxxx
AND   RA, RB       1100xxxx
OR    RA, RB       1101xxxx
XOR   RA, RB       1110xxxx
CMP   RA, RB       1111xxxx
LD    RA, RB       0000xxxx
ST    RA, RB       0001xxxx
DATA  RB, Addr     001000xx xxxxxxxx
JMPR  RB           001100xx
JMP   Addr         01000000 xxxxxxxx
JCAEZ Addr         0101caez xxxxxxxx (carry, a larger, equal, zero)
CLF                01100000
IN    Data, RB     011100xx
IN    Addr, RB     011101xx
OUT   Data, RB     011110xx
OUT   Addr, RB     011111xx
"""

def main():
    code = str()
    with open("asm.txt") as code:
        code = code.read()
    code = [line.split(' ') for line in code.split('\n')]

    symbol_table = {}
    ram = []

    while code:
        line = code.pop(0)
        for i, item in enumerate(line):
            try:
                line[i] = symbol_table[item]
            except KeyError:
                try:
                    line[i] = int(item, 0)
                except ValueError:
                    pass

        match line[0].lower():
            case 'add':
                ram.append(f'1000{line[1]:02b}{line[2]:02b}')
            case 'shr':
                ram.append(f'1001{line[1]:02b}{line[2]:02b}')
            case 'shl':
                ram.append(f'1010{line[1]:02b}{line[2]:02b}')
            case 'not':
                ram.append(f'1011{line[1]:02b}{line[2]:02b}')
            case 'and':
                ram.append(f'1100{line[1]:02b}{line[2]:02b}')
            case 'or':
                ram.append(f'1101{line[1]:02b}{line[2]:02b}')
            case 'xor':
                ram.append(f'1110{line[1]:02b}{line[2]:02b}')
            case 'cmp':
                ram.append(f'1111{line[1]:02b}{line[2]:02b}')
            case 'ld':
                ram.append(f'0000{line[1]:02b}{line[2]:02b}')
            case 'st':
                ram.append(f'0001{line[1]:02b}{line[2]:02b}')
            case 'data':
                ram.append(f'001000{line[1]:02b}')
                ram.append(f'{line[2]:08b}')
            case 'jmpr':
                ram.append(f'001100{line[1]:02b}')
            case 'jmp':
                ram.append(f'01000000')
                ram.append(f'{line[1]:08b}')
            case 'jcaez':
                ram.append(f"0101{''.join([1 if char in line[1] else 0 for char in ['c','>','=','0']])}")
                ram.append(f"{line[2]:08b}")
            case 'clf':
                ram.append(f"01100000")
            case 'label':
                symbol_table[line[1]] = len(ram)
            case _:
                pass


    for i, line in enumerate(ram):
        # print(i, '\t', line)
        print(line)



if __name__ == '__main__':
    main()