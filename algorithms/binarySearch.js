const findIndex = (list, item) => {
    let low = 0
    let high = list.length - 1

    while(low <= high) {
        const valueIndex = Math.round((low + high) / 2)
        const value = list[valueIndex]

        if (value === item) {
            return valueIndex
        }

        if (value > item) {
            high = valueIndex - 1
        } else {
            low = valueIndex + 1
        }
    }
}
