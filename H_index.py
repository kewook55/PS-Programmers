"""
이 문제의 정답은 citations안의 값이 아니라 citations의 인덱스가 된다는걸 참고해야한다/

input
[20,19,18,1]
output
3

input
[20,19,18,17]
output
4

따라서 오름차순으로 정렬을하고 앞에서부터 한 개씩 판가름 해준다.
만약 i번째의 인용횟수가 h이상의 인용횟수들중에 최소값이라면 h이상의 인용횟수들을 return해준다.
"""
def solution(citations):
    citations.sort()
    size = len(citations)
    for i in range(size) :
        if citations[i] >= size - i :
            return size -i
    
    return 0