# PQC Integration Design for IPsec

## Threat Model
Harvest-now-decrypt-later attacks against classical Diffie–Hellman.

## Design Approach
Replace or augment Diffie–Hellman in IKE_SA_INIT with ML-KEM (Kyber).

## Hybrid Key Derivation
SKEYSEED = KDF( DH_secret || Kyber_secret )

## Benefits
- Quantum resistance for recorded traffic
- Backward compatibility
- No changes to IPsec ESP data plane

## Future Work
- StrongSwan IKEv2 source integration
- Negotiation of PQC groups
- Performance evaluation
