# Post-Quantum Secure IPsec using ML-KEM (Kyber)

This repository explores integrating post-quantum cryptography into IPsec VPNs to mitigate
harvest-now-decrypt-later attacks.

## Scope
- Built a classical IPsec VPN using StrongSwan and IKEv2
- Identified Diffie–Hellman in IKE_SA_INIT as the quantum-vulnerable component
- Implemented ML-KEM (Kyber) using liboqs
- Designed a hybrid DH + Kyber key derivation for IKEv2

## Repository Structure
- ipsec-baseline/ : Notes on StrongSwan, IKEv2, and DH usage
- kyber-demo/     : ML-KEM (Kyber) and hybrid key derivation prototypes
- docs/           : PQC integration design for IPsec

## Status
This is a research prototype and design exploration.
StrongSwan source code is not modified yet.

## Motivation
Replacing Diffie–Hellman with post-quantum key exchange protects IPsec VPNs against
future quantum adversaries capable of harvesting encrypted traffic today.
