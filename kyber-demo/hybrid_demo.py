import hashlib
import os

# Simulated classical Diffie–Hellman shared secret
dh_secret = os.urandom(32)

# Simulated ML-KEM (Kyber) shared secret
kyber_secret = os.urandom(32)

# Hybrid key derivation (as recommended by NIST / IETF)
hybrid_secret = hashlib.sha256(dh_secret + kyber_secret).digest()

print("DH secret length:", len(dh_secret))
print("Kyber secret length:", len(kyber_secret))
print("Hybrid key length:", len(hybrid_secret))
