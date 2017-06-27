import cs50
import sys
import crypt

def main():
    # Validate arguments
    if len(sys.argv) != 2:
        print("Usage: {} hash".format(sys.argv[0]))
        exit(1)

    hash_code = sys.argv[1]

    list_1 = get_list(1)
    # print(list_1)
    result_1 = compare(list_1, hash_code)
    if result_1['found']:
        print(result_1['code'])

    list_2 = get_list(2)
    # print(list_2)
    result_2 = compare(list_2, hash_code)
    if result_2['found']:
        print(result_2['code'])     
    
    
    list_3 = get_list(3)
    result_3 = compare(list_3, hash_code)
    # print(list_3)
    if result_3['found']:
        print(result_3['code'])  
    
    list_4 = get_list(4)
    #print(list_4)    
    result_4 = compare(list_4, hash_code)
    if result_4['found']:
        print(result_4['code'])     
   
def compare(poss_list, hash_code):
    salt = "50"
    for element in poss_list:
        if crypt.crypt(element, salt) == hash_code:
            return {'found' : True, 'code' : element}
    
    return {'found' : False, 'code' : None}

def get_list(n):
    
    if n == 1:
        
        list_1 = []
        for i in range(ord('a'), ord('z') + 1):
            list_1.append(chr(i))
        for i in range(ord('A'), ord('Z') + 1):
            list_1.append(chr(i))
        return list_1 
        
    if n == 2:
        
        list_2 = []
        list_1 = get_list(1) # [a...z, A...Z]
        index = 0
        # [a,a]...[a, z] [a,A] ... [a, Z]
        for x in list_1:
            for i in range(ord('a'), ord('z') + 1):
                list_2.append(x)
                list_2[index] += (chr(i))
                index += 1
            for i in range(ord('A'), ord('Z') + 1):
                list_2.append(x)
                list_2[index] += (chr(i))
                index += 1
        return list_2
        
    if n == 3:
        
        list_3 = []
        list_2 = get_list(2)
        index = 0
        for x in list_2:
            for i in range(ord('a'), ord('z') + 1):
                list_3.append(x)
                list_3[index] += (chr(i))
                index += 1
            for i in range(ord('A'), ord('Z') + 1):
                list_3.append(x)
                list_3[index] += (chr(i))
                index += 1
        return list_3
        
    if n == 4:
        
        list_4 = []
        
        list_3 = get_list(3)
        index = 0
        for x in list_3:
            for i in range(ord('a'), ord('z') + 1):
                list_4.append(x)
                list_4[index] += (chr(i))
                index += 1
            for i in range(ord('A'), ord('Z') + 1):
                list_4.append(x)
                list_4[index] += (chr(i))
                index += 1
        return list_4

if __name__ == "__main__":
    main()