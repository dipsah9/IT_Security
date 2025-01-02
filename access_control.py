# Access Control Matrix
access_matrix = {
    "Dipendra": {"File1": ["read"], "File2": ["read", "write"]},
    "Sah": {"File1": ["write"], "File2": ["read"]},
    "Admin": {"File1": ["read", "write", "delete"], "File2": ["read", "write", "delete"]},
}

# Function to check access
def check_access(user, file, operation):
    if user in access_matrix and file in access_matrix[user]:
        if operation in access_matrix[user][file]:
            return f"Access granted for {user} to {operation} {file}"
    return f"Access denied for {user} to {operation} {file}"

# Add Permission
def add_permission(user, file, operation):
    if user not in access_matrix:
        access_matrix[user] = {}
    if file not in access_matrix[user]:
        access_matrix[user][file] = []
    if operation not in access_matrix[user][file]:
        access_matrix[user][file].append(operation)
    print(f"Permission added: {user} can {operation} {file}")

# Remove Permission
def remove_permission(user, file, operation):
    if user in access_matrix and file in access_matrix[user]:
        if operation in access_matrix[user][file]:
            access_matrix[user][file].remove(operation)
            print(f"Permission removed: {user} cannot {operation} {file} anymore")


# Test Cases
remove_permission("Dipendra", "File1", "read")
print(check_access("Dipendra", "File1", "read"))  # Access granted
print(check_access("Dipendra", "File1", "write"))  # Access denied
print(check_access("Admin", "File1", "delete"))  # Access granted
print(check_access("Sah", "File2", "read"))  # Access granted
add_permission("Guest", "File1", "read")

print(check_access("Guest", "File1", "read"))  # Access denied
