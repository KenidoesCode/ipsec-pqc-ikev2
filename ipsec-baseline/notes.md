# IPsec Baseline Observations

- Implemented a classical IPsec VPN using StrongSwan
- Used IKEv2 with Diffie–Hellman (MODP 2048)
- Observed IKE_SA_INIT exchange in logs
- Identified Diffie–Hellman as the only quantum-vulnerable component
- ESP data plane remains unchanged
