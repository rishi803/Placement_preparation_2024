**Approach:**
* want to shift all left child to right
* so in recursion process right then left so that right will process before left
* simply make right node pointing to its previous node and left as null and update prev as node