def getThousandDigits():
    with open('1000-digit-number', 'r') as file:
        thousandDigits = file.read().replace('\n', '')
    return thousandDigits

def setThirteenAdjacentDigits(thousandDigits):
    thirteenAdjacentDigitsList = []
    positionStart = 0
    positionEnd = positionStart + 12
    rounds = 1
    edgeBoundary = 12

    while (rounds <= len(thousandDigits)-edgeBoundary):
        tmp = ""
        for digit in range(positionStart, positionEnd + 1):
            tmp += thousandDigits[digit]

        thirteenAdjacentDigitsList.append(tmp)
        positionStart += 1
        positionEnd += 1
        rounds += 1

    return thirteenAdjacentDigitsList

def checkForNoZeros(item):
    for digit in item:
        if digit is '0':
            return False
    return True

def getAdjacentDigitsWithoutZeros(thirteenAdjacentDigitsList):
    adjacentDigitsWithoutZeros = []

    for item in thirteenAdjacentDigitsList:
        if checkForNoZeros(item):
            adjacentDigitsWithoutZeros.append(item)

    return adjacentDigitsWithoutZeros

def multiplyEachDigit(adjacentDigitsWithoutZeros):
    products = []

    for item in adjacentDigitsWithoutZeros:
        productFromDigits = 1
        for digit in item:
            productFromDigits = productFromDigits * int(digit)
        products.append(productFromDigits)

    return products

def getGreatestProduct(products):
    greatestProduct = products[0]
    for value in products:
        if (value >= greatestProduct):
            greatestProduct = value
    return greatestProduct
