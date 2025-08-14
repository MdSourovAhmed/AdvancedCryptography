import csv

def sieve_prime_count(n):
    """Generate all prime numbers up to n using Sieve of Eratosthenes."""
    if n < 2:
        return []
    
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    primes = []
    
    for p in range(2, int(n ** 0.5) + 1):
        if sieve[p]:
            # primes.append(p)
            for multiple in range(p*p, n+1, p):
                sieve[multiple] = False
    
    # Add remaining primes > sqrt(n)
    primes.extend([i for i in range(2, n+1) if sieve[i]])
    
    return primes

def main():
    try:
        # Read from input.csv (commented out for testing)
        with open('input.csv', 'r') as infile:
            max_num = int(next(csv.reader(infile))[0])
        
        # max_num = 178  # Test value
        
        primes = sieve_prime_count(max_num)
        prime_count = len(primes)  # Count of primes, not sum
        
        print("Prime numbers found:", primes)
        
        with open('output.csv', 'w', newline='') as outfile:
            # Write both count and primes (adjust as needed)
            csv.writer(outfile).writerow([prime_count])
            csv.writer(outfile).writerow(primes)
        
        print(f"Found {prime_count} primes up to {max_num}")
    
    except FileNotFoundError:
        print("Error: input.csv not found")
    except ValueError:
        print("Error: Invalid input format")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
