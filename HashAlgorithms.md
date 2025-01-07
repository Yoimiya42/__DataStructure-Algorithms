## Design Principles
To reduce the probability of hash collision, the hash function should have the following characteristics:
1. **Determinism**: The same input should always produce the same hash value.
2. **Efficiency**:  The smaller the computational overhead, the more practical the hash function.
3. **Uniform distribution**： The hash function should as evenly as possible distribute the key-value pairs across the hash table.
Additionally, hash algorithms need high-level security:
4. **Unidirectionality**: It should be impossible to deduce any information about the input from the hash value.
5. **Collision resistance**: It should be extremely difficult to find two different inputs that produce the same hash value.
6. **Avalanche effect**: Minor changes in the input should lead to significant and unpredictable changes in the output.

## Design of Hash Algorithms

**Additives Hash**  

**Multiplicative Hash**  

**XOR Hash**  

**Rotating Hash**

