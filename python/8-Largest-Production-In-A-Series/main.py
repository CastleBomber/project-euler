
def main():

    stringArray = []

    with open('num', 'r') as file:
        ThousandDigitString = file.read().replace('\n', '')

    for x in ThousandDigitString:
        stringArray = ThousandDigitString.split('0')


    size13PlusArray = []

    # eliminate lengths < 13
    for y in stringArray:
        if len(y) >= 13:
            size13PlusArray.append(y)

    readyToBeChecked = [] # !!!
    tooBigStrings = []

    # fill up array with all possibilities
    # includes size 13 && up
    # will need to deal with too big strings
    for item in size13PlusArray:
        if len(item) > 13:

            tooBigStrings.append(item)
        else:
            readyToBeChecked.append(item)


    # cut down big strings
    for bigItem in tooBigStrings:
        extra = len(bigItem) - 13
        i = 0
        while extra > i:
            sub = bigItem[(0+i): (13+i)]
            readyToBeChecked.append(sub)
            i += 1


    products = []

    for num in readyToBeChecked:
        productTotal = 1
        for digit in num:
            productTotal = int(digit) * productTotal
        products.append(productTotal)


    # we now have array of ints
    # the ints are the products (multiplication done)
    # lets check to see which is the biggest

    largestProduct = 0

    for z in products:
        if z > largestProduct:
            largestProduct = z

    print(largestProduct)



main()
