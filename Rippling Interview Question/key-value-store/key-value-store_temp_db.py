class Database:
    def __init__(self):
        self.db = {}
        self.temp_db = {}
        self.in_transaction = False
    
    def  set(self, key, value):
        if not self.in_transaction:
            self.db[key] = value
        else:
            self.temp_db[key] = value
    
    def delete_key(self, key):
        if not self.transaction:
            if key in self.db:
                del self.db[key]
            else:
                return "KeyError: Key not Found"
        else:
            if key in self.temp_db:
                self.temp_db[key] = "DELETED"
            elif key in self.db:
                self.temp_db[key] = "DELETED"
            else:
                return "KeyError: Key not Found"
    
    def get(self, key):
        if key in self.temp_db:
            if key in self.temp_db == "DELETED":
                return "KeyError: Key not Found"
            return self.temp_db[key]
        return self.db.get(key, "KeyError: Key not Found")

    def begin(self):
        self.in_transaction = True
        self.temp_db.clear()
    
    def commit(self):
        if not self.in_transaction:
            return "TransactionError: No active transaction"
        
        for key, value in self.temp_db.item():
            if value == "DELETED":
                self.db.pop(key, None)
            else:
                self.db[key] = value

        self.temp_db.clear()
        self.in_transaction = False
    
    def rollback(self):
        if not self.in_transaction:
            return "TransactionError: No active trasaction"
        
        self.temp_db.clear()
        self.in_transaction = False

db = Database()
assert db.get("key0") == "KeyError: Key not Found", "Test case Failed"
print("Test case passed")
