class stack:
    def __init__(self):
        self.items = []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def isEmpty(self):
        return not self.items
    def size(self):
        return len(self.items)

st = stack()
ans = 0
str = input()

for i in range(0, len(str)):
    if str[i] == '(' and str[i+1] == ')':
        ans += st.size()
    elif str[i] == '(':
        st.push(str[i])
    elif str[i] == ')' and str[i-1] == '(':
        continue
    elif st.size() > 0 and str[i] == ')':
        st.pop()
        ans += 1

print(ans)
