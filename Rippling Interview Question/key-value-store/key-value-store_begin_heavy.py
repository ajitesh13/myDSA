class Database:
    def __init__(self):
        self.global_db = {}  # The global datastore
        self.transaction_stack = []  # Stack to maintain snapshots for transactions

    def set(self, key, value):
        if self.transaction_stack:
            # Modify the latest snapshot during a transaction
            self.transaction_stack[-1][key] = value
        else:
            # Modify the global state if no transaction is active
            self.global_db[key] = value

    def get(self, key):
        if self.transaction_stack:
            # Look for the key in the latest snapshot
            if key in self.transaction_stack[-1]:
                return self.transaction_stack[-1][key]
            return "Key not found!"
        return self.global_db.get(key, "Key not found!")

    def delete_key(self, key):
        if self.transaction_stack:
            # Delete from the latest snapshot
            if key in self.transaction_stack[-1]:
                del self.transaction_stack[-1][key]
            elif key in self.global_db:
                self.transaction_stack[-1][key] = "DELETED"
            else:
                print("Key not found!")
        else:
            # Delete from the global state
            if key in self.global_db:
                del self.global_db[key]
            else:
                print("Key not found!")

    def begin(self):
        # Create a full copy (snapshot) of the global state
        snapshot = self.global_db.copy()
        self.transaction_stack.append(snapshot)

    def commit(self):
        if not self.transaction_stack:
            print("No active transaction to commit!")
            return
        # Replace the global state with the latest snapshot
        self.global_db = self.transaction_stack.pop()
        # Clear any remaining snapshots (single-level transactions only)
        self.transaction_stack.clear()

    def rollback(self):
        if not self.transaction_stack:
            print("No active transaction to rollback!")
            return
        # Discard the latest snapshot
        self.transaction_stack.pop()

# Test the implementation
def begin_heavy_tests():
    db = Database()

    # Basic operations
    db.set("key0", "val0")
    print(db.get("key0"))  # Output: val0

    # Begin transaction
    db.begin()
    print(db.get("key0"))  # Output: val0
    db.set("key1", "val1")
    print(db.get("key1"))  # Output: val1
    db.rollback()
    print(db.get("key1"))  # Output: Key not found!

    # Nested transactions (single-level only)
    db.begin()
    db.set("key2", "val2")
    print(db.get("key2"))  # Output: val2
    db.commit()
    print(db.get("key2"))  # Output: val2

    # Attempting to commit or rollback with no active transaction
    db.commit()  # Output: No active transaction to commit!
    db.rollback()  # Output: No active transaction to rollback!

begin_heavy_tests()
