# 🔐 Post-Quantum Secure IPsec using ML-KEM (Kyber)

This repository explores how **post-quantum cryptography (PQC)** can be integrated into
**IPsec VPNs** to mitigate *harvest-now-decrypt-later* attacks, with a focus on
**ML-KEM (Kyber)** as standardized by NIST.

The work follows a **research-driven, protocol-aware approach**, starting from a
classical IPsec baseline and progressing toward a post-quantum key exchange design
for IKEv2.

---

## 🎯 Motivation

Modern IPsec VPNs rely on **Diffie–Hellman (DH)** during the IKEv2 `IKE_SA_INIT` phase
to establish session keys. While secure against classical adversaries, DH is
**vulnerable to future quantum attacks** (e.g., Shor’s algorithm).

This enables a serious threat model:

> **Harvest now, decrypt later** — attackers can record encrypted VPN traffic today
> and decrypt it in the future once large-scale quantum computers become available.

**ML-KEM (Kyber)** provides a post-quantum alternative for key establishment and
directly addresses this risk.

---

## 🧭 Project Scope

This repository documents three deliberate phases:

### 1️⃣ IPsec Baseline Analysis
- Built a classical IPsec VPN using **StrongSwan** and **IKEv2**
- Observed the `IKE_SA_INIT` exchange and identified **Diffie–Hellman** as the
  quantum-vulnerable component
- Confirmed that the **ESP data plane** does not require modification

### 2️⃣ Post-Quantum Key Exchange Validation
- Implemented **ML-KEM (Kyber)** using the Open Quantum Safe **liboqs** library
- Demonstrated key generation, encapsulation, and decapsulation
- Verified shared secret agreement and examined parameter sizes

### 3️⃣ PQC Integration Design
- Designed a **hybrid key derivation** for IKEv2 combining classical DH and ML-KEM
- Mapped the design explicitly to the `IKE_SA_INIT` phase
- Preserved IPsec compatibility while eliminating harvest-now-decrypt-later risk

---

## 🧠 Core Idea

The central design principle is a **hybrid key exchange**:
This approach ensures that:
- Security is preserved if *either* classical or post-quantum assumptions hold
- Transition risks during PQC migration are minimized
- The IPsec data plane (ESP) remains unchanged

This aligns with current **NIST guidance** and emerging **IETF post-quantum IPsec drafts**.

---
## ⚠️ Scope and Limitations

- This is a **research prototype and design exploration**
- StrongSwan source code is **not modified yet**
- Authentication remains classical (e.g., RSA certificates)
- Focus is intentionally limited to **key establishment**, which is the relevant
  surface for harvest-now-decrypt-later attacks

These choices reflect standard practice in **protocol and cryptographic research**.

---

## 🔮 Future Work

- Native ML-KEM support inside StrongSwan’s IKEv2 implementation
- PQC-capable IKE negotiation mechanisms
- Performance and latency evaluation
- Optional post-quantum authentication (e.g., ML-DSA)

---

## 🏷️ Keywords

IPsec · IKEv2 · Post-Quantum Cryptography · ML-KEM · Kyber · StrongSwan · VPN · PQC

---

## 👤 Author

**Pranauv Shrinaath S**  
Research-focused exploration of post-quantum secure networking
