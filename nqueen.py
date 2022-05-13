result = []
def isSafe(board, row, col,n):
 
    # Check this row on left side
    for i in range(col):
        if (board[row][i]):
            return False

    # Check upper diagonal on left side
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    # Check lower diagonal on left side
    i = row
    j = col
    while j >= 0 and i < n:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True
 
def NqueenSolve(board, col,n):
    if n<=26:
        chars = True
    else:
        chars = False
    if (col == n):
        v = []
        for i in range(len(board)):
          for j in range(len(board[i])):
            if chars and board[i][j] == 1:
              v.append(chr(65+i)+str(j+1))
            elif not chars and board[i][j] == 1:
              v.append(j+1)
        result.append(v)
        return True
    res = False
    
    for i in range(n):
        if (isSafe(board, i, col,n)):
 
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement
            # is possible       
            res = NqueenSolve(board, col + 1,n) or res
            board[i][col] = 0  # BACKTRACK
    return res
 
def Nqueen(n):
    result.clear()
    board = [[0 for j in range(n)] for i in range(n)]
    NqueenSolve(board, 0,n)
    result.sort()
    return result
 
print("N-Queen Problem\n")
no_of_rows = int(input("Enter the number of rows in problem: "))
res = Nqueen(no_of_rows)
print("The Total number of solutions are:",len(res))
for req in res:
    print(req)