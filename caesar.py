import cs50
import sys

def main():
    argument = len(sys.argv)
    if argument != 2:
        print("error")
        exit(1)
        
    else:
        key = int(sys.argv[1])
        print("plaintext: ",end="")
        text = cs50.get_string()
        print("ciphertext: ",end="")
        for c in text:
            if c.isalpha():
                if c.isupper():
                    x = ((ord(c)-65)+key)%26
                    letter = chr(x+65)
                    print(letter,end="")
                    
                if c.islower():
                    x = ((ord(c)-97)+key)%26
                    letter = chr(x+97)
                    print(letter,end="")
                    
            else:
                print(c,end="")
                
        print()
        
if __name__ == "__main__":
    main()
                
                    
                
    