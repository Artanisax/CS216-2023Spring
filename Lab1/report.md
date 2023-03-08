1. $$O(nmlog(nm))$$
2. The matching is stable is there is no any pair $$(s, c)$$, such that

    - student $$s$$ is not enrolled to college $$c$$

    - student $$s$$ prefers college $$c$$ than $$s$$'s current admission state (we could consider unmatched to be of 0 evaluation value)

    - either is capable to enroll more student and $$s$$ can increase $$c$$'s satisfaction value, or $$c$$ prefers $$c$$ than some other student $$s'$$ that has been enrolled to $$c$$

3. Pf. (by contradiction) (We can consider unenrollment to be a college evaluated by every student with value 0, as well as well students evaluated by every college with value 0)
    - Suppose $$(s, c)$$ is a unstable pair: $$s$$ is enrolled in $$c'$$, $$s$$ prefers college $c$ (i.e. $$eval (s, c') < eval(s, c)$$), and $$c$$ prefers not to accept $$s$$ or prefers another student $$s'$$ (i.e. $$eval(c, s') \leq eval(c, s)$$).
        - Case 1: $$s$$ never applied for $$c$$. Because students applied in decreasing order or preference, so $$s$$ prefers $$c'$$ to $$c$$, then $$(s, c)$$ is stable.
        - Case 2: $$s$$ applied for $$c$$. $$c$$ unenrolled $$s$$ (sooner or later), i.e. $$c$$ prefer other students than $$s$$, so $$(s, c)$$ is stable.

4. Yes, GS produces a student-optimal matching.