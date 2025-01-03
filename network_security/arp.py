import subprocess

def list_arp_table():
    # Run the `arp -a` command
    result = subprocess.run(['arp', '-a'], stdout=subprocess.PIPE, text=True)
    print("ARP Table Entries:\n")
    print(result.stdout)

if __name__ == "__main__":
    list_arp_table()

