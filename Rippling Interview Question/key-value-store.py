class KeyValueStore:
    def __init__(self):
        self.store = {}  # Global state
        self.transactions = []  # Stack to maintain transactional state

    def set(self, key, value):
        if self.transactions:
            self.transactions[-1][key] = value
        else:
            self.store[key] = value

    def get(self, key):
        if self.transactions:
            # Look for the key in the latest transaction first
            for transaction in reversed(self.transactions):
                if key in transaction:
                    return transaction[key]
        return self.store.get(key, None)

    def delete(self, key):
        if self.transactions:
            self.transactions[-1][key] = None
        elif key in self.store:
            del self.store[key]

    def begin(self):
        # Start a new transaction
        self.transactions.append({})

    def commit(self):
        if not self.transactions:
            raise Exception("No active transaction to commit.")

        current_transaction = self.transactions.pop()
        for key, value in current_transaction.items():
            if value is None:
                self.store.pop(key, None)
            else:
                self.store[key] = value

    def rollback(self):
        if not self.transactions:
            raise Exception("No active transaction to rollback.")

        # Discard the latest transaction
        self.transactions.pop()


# Unit tests
def test_key_value_store():
    db = KeyValueStore()

    # Part 1: Basic operations
    db.set("key1", "val1")
    assert db.get("key1") == "val1", "Test Case 1 Failed"
    db.delete("key1")
    assert db.get("key1") is None, "Test Case 2 Failed"

    # Part 2: Transactions
    db.set("key0", "val0")
    assert db.get("key0") == "val0", "Test Case 3 Failed"

    db.begin()
    assert db.get("key0") == "val0", "Test Case 4 Failed"

    db.set("key1", "val1")
    assert db.get("key1") == "val1", "Test Case 5 Failed"

    db.commit()
    assert db.get("key1") == "val1", "Test Case 6 Failed"

    db.begin()
    db.set("key2", "val2")
    assert db.get("key2") == "val2", "Test Case 7 Failed"

    db.rollback()
    assert db.get("key2") is None, "Test Case 8 Failed"

    print("All test cases passed!")


if __name__ == "__main__":
    test_key_value_store()
