export const quicksort = (arr, start, end) =>{
    
    if(start >= end)
        return;

    let index = partition(arr, start, end);
    //console.log(index)

    quicksort(arr, start, index - 1);
    quicksort(arr, index + 1, end);
}

const partition = (arr, start, end) =>{
    
    //We use the last element as the pivot

    const pivotValue = arr[end];

    let pivotIndex = start;

    for(let i = start; i < end; i++){
        if(arr[i] < pivotValue){
            // Swapping elements 
            [arr[i], arr[pivotIndex]] = [arr[pivotIndex], arr[i]];

            pivotIndex++;
        }

    }

    // Putting  the pivot value in the middle

    [arr[pivotIndex], arr[end]] = [arr[end], arr[pivotIndex]];

    return pivotIndex;

}

