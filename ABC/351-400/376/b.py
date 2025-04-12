N,Q=map(int,input().split())
L,R=1,2
ans=0
for _ in range(Q):
  H,T=input().split()
  T=int(T)
  if H=='L':
    to=(T-L)%N
    ng=(R-L)%N
    if ng<to: ans+=N-to
    else: ans+=to
    L=T
  else:
    to=(T-R)%N
    ng=(L-R)%N
    if ng<to: ans+=N-to
    else: ans+=to
    R=T

print(ans)


# n, q = map(int, input().split())
# h = []
# t = []

# for i in range(q):
#     h_i, t_i = input().split()
#     h.append(h_i)
#     t.append(int(t_i))

# lpos = 0
# rpos = 1
# count = 0
# for i in range(q):
#     if(h[i] == 'L'):
#         if(rpos > lpos):
#             if(t[i] > rpos):
#                 count += (lpos - 0) + (n-1 - t[i]-1)
#             else:
#                 count += abs(lpos - t[i]-1)
#         else:
#             if(t[i] > lpos):
#                 count += (rpos - 0) + (n-1 - t[i]-1)
#             else:
#                 count += abs(rpos - t[i]-1)
#     elif(h[i] == 'R'):
#         if(lpos > rpos):
#             if(t[i] > lpos):
#                 count += (rpos - 0) + (n-1 - t[i]-1)
#             else:
#                 count += abs(rpos - t[i]-1)
#         else:
#             if(t[i] > rpos):
#                 count += (lpos - 0) + (n-1 - t[i]-1)
#             else:
#                 count += abs(lpos - t[i]-1)

# print(count)
