def findPath(start, end, tree, dp, visited): # [xor, or, and]
    if start == end:
        return [0, 0, 0]
    if dp[start][end] != None:
        return dp[start][end]
    # iterate over neighbours of start
    for neigh in tree[start]:
        a, b= neigh[0], neigh[1]
        if a not in visited:
            if a== end:
                dp[start][end]= [b, b, b]
                return [b, b, b]
            visited.add(a)
            tra= findPath(a, end, tree, dp, visited)
            if tra != None:
                dp[start][end]= [tra[0]^b, tra[1]|b, tra[2]&b]
                return [tra[0]^b, tra[1]|b, tra[2]&b]
    return None
    
def getPathXORAND(treeNodes, treeFrom, treeTo, treeWeights, queries):
    n= len(treeFrom) # number of edges
    dic= {}
    # for i in range(1, n+1):
    #     dic[i]= [0 for j in range(n+1)]
    for i in range(n):
        s, e, w= treeFrom[i], treeTo[i], treeWeights[i]
        dic[s]= dic.get(s, []) + [[e, w]]
        dic[e]= dic.get(e, []) + [[s, w]]
    print(dic)
    dp= [[None for i in range(treeNodes+1)] for j in range(treeNodes+1)]
    k= len(queries)
    ans= []
    for i in range(k):
        qry= queries[i]
        start, end= qry[0], qry[1]
        print(start, end)
        lmt= 2**21-1
        ans.append(sum(findPath(start, end, dic, dp, set())))
    return ans
