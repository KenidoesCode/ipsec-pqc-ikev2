#include <stdio.h>
#include <string.h>
#include <oqs/oqs.h>

int main() {
    OQS_KEM *kem = OQS_KEM_new(OQS_KEM_alg_ml_kem_768);
    if (!kem) {
        printf("ML-KEM not supported\n");
        return 1;
    }

    uint8_t public_key[kem->length_public_key];
    uint8_t secret_key[kem->length_secret_key];
    uint8_t ciphertext[kem->length_ciphertext];
    uint8_t shared_secret_client[kem->length_shared_secret];
    uint8_t shared_secret_server[kem->length_shared_secret];

    OQS_KEM_keypair(kem, public_key, secret_key);
    OQS_KEM_encaps(kem, ciphertext, shared_secret_client, public_key);
    OQS_KEM_decaps(kem, shared_secret_server, ciphertext, secret_key);

    printf("=== ML-KEM (Kyber) Demo ===\n");
    printf("Public key size: %zu bytes\n", kem->length_public_key);
    printf("Ciphertext size: %zu bytes\n", kem->length_ciphertext);
    printf("Shared secret size: %zu bytes\n", kem->length_shared_secret);

    if (memcmp(shared_secret_client, shared_secret_server,
               kem->length_shared_secret) == 0) {
        printf("Shared secret MATCHED ✅\n");
    } else {
        printf("Shared secret MISMATCH ❌\n");
    }

    OQS_KEM_free(kem);
    return 0;
}
