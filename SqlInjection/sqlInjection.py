import sqlite3

# Setup database
connection = sqlite3.connect(":memory:")
cursor = connection.cursor()
cursor.execute("CREATE TABLE users (id INTEGER, name TEXT)")
cursor.execute("INSERT INTO users VALUES (1, 'Alice'), (2, 'Bob')")

#Vulnerable 
def get_user(user_id):
    query = f"SELECT * FROM users WHERE id = {user_id}"
    cursor.execute(query)
    return cursor.fetchall()

#Test SQL Injection
print(get_user("1 OR 1=1"))  # Injection!

#Fix with parameterized query
def get_user_safe(user_id):
    query = "SELECT * FROM users WHERE id = ?"
    cursor.execute(query, (user_id,))
    return cursor.fetchall()

print(get_user_safe(1))  #this one is safe

#from here we can see vulnerability in the database. only because of the carelessness in writting the function
#attackers can benefit from it . 

