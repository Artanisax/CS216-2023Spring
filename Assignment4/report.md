## 3-SAT $≤_p$ 3-Color

### Definition

A 3-coloring problem for undirected graphs is an assignment of colors to the nodes of the graph such that no two adjacent vertices have the same color, and **at most 3** colors are used to complete color the graph.

### Proof

Consider the simplest graph that the constraint of 3-color works:

![image-20230514212816143](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20230514212816143.png)

Obviously, here we need to use 3 different colors to color each vertex separately. To simplify, we can only use 2 variables to show the relation: $v_1 \  v_2\ \overline{v_2}$, or **Base**, **True** and **False** as 3 colors. This could be interpreted as "$v$ and $\overline v$ must be colored differently, and neither of them it is colored with the same color of the base vertex" or "once the base vertex is confirmed, the rest two vertices can only be one true while the other false". That is to say, there is at least one vertex in this triangle that should be colored as **Ture**.

To prove that **3-SAT** can be reduced to **3-Color**, we now assume a graph $G$ has a 3-color solution. Consider an clause ($v_1 \vee \overline{v}_2 \vee v_3$). We can expand it into the graph below. Noticed that **IFF** there is at least one of the three node to be true can the whole graph be colored with 3 colors only.

![无标题](C:\Users\lenovo\Desktop\Temp\无标题.png)

As the operator between clauses is $\wedge$, we can simply do the same expansion for all clauses and the put them together through vertices that stand for the same variables. If the whole graph has a **3-Color** solution, the original clauses are all true. Clearly the expansion time complexity is $O(n)$, so by doing so we succeed in reducing **3-SAT** into **3-Color**. And we can say that **3-SAT** $≤_p$ **3-Color**.