function getHighest(list) {
    if (list.length === 0) {
        return 0;
    }

    const highestValue = getHighest(list.slice(1))

    return list[0] > highestValue ? list[0] : highestValue
}

console.log(getHighest([1,2,8,4,5]))