/**
 * @file crypto.h Cryptography header file.
 *
 * Cryptography header file for PolySat library.
 *
 * @author Greg Manyak <gregmanyak@gmail.com>
 */

//TODO: FIX THE DOCUMENTATION HERE, RETVALS INCORRECT

#ifndef _CRYPTO_H_
#define _CRYPTO_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Configuration settings **/
/// Define for SHA256 hash being used
#define SHA256

/// Define for OSX development environment
#define OSX_DEV

// Directory for public key (.pem) files
#ifdef _LINUX_DEV
#define PUBKEY_DIR      "/home/polysat/gmanyak/certs/pubCerts/"
#else
#define PUBKEY_DIR      "/certs/"
#endif

#ifdef SHA256
#define HASH_LEN        SHA256_DIGEST_LENGTH
#endif

#define SSL_SUCCESS     1

/// Signature length for current configuration
#define CRYPTO_SIG_LEN  128

/**
 * Data Hash
 * ----------------------
 *  Uses default hash algorithm to create hash of data.
 *
 *  Allocates its own memory. Caller is responsible for free'ing.
 *
 *  @param  data     Data to be hashed.
 *  @param  dataLen  Length, in bytes, of the data.
 *  @param  hash     Location for hash to be stored.
 *  @param  hashLen  Length, in bytes, of the hash.
 */
void data_hash(unsigned char * data, size_t dataLen,
         unsigned char ** hash, size_t * hashLen);

void crypto_init(void);

/**
 * Data Verification with a Signature
 * ----------------------------------
 *  This function iterates through a directory of public keys, attempting to
 *  verify the given signature with the hash of the given data.
 *
 *  @param  data     The un-hashed, raw data, which was signed.
 *  @param  dataLen  Length, in bytes, of the data.
 *  @param  sig      The signature of the data.
 *  @param  sigLen   Length, in bytes, of the data.
 *
 *  @retval -1       An error has occured, message printed out to stderr.
 *                   Signature has not been verified.
 *          0        Signature has been verified.
 */
int data_verify(unsigned char * data, unsigned char dataLen,
               unsigned char * sig, size_t sigLen);

/**
 * Digital Signature Verification
 * --------------------------------
 *  Calls data_verify and does not require user to know signature length.
 *
 *  @param  data     Entirety of the message sent. 
 *  @param  dataLen  Length, in bytes, of message.
 *
 *  @returns         Success or failure of signature verification.
 *  @retval -1       Signature has not been verified or an error occured.
 *          0        Signature has been verified.
 */
int signature_verify(unsigned char * data, size_t dataLen);

/**
 * Data Signature Generation
 * -------------------------
 *  Generates a private key signature for a hash of the specified data.
 *
 *  NOTE: The signature belongs to the hash of the data, not the data itself.
 *
 *  @param   data        Data to generate signature for.
 *  @param   dataLen     Length, in bytes, of the data.
 *  @param   sigOut      Pointer to the location for the signature.
 *  @param   sigLenOut   Pointer to the location for the signature length.
 *
 *  @retval -1          An error has occured, message printed out to stderr.
 *                      Signature has not been generated.
 *          0           Signature has been generated.
 */
int data_sign(unsigned char * data, unsigned char dataLen,
            unsigned char ** sigOut, size_t * sigLenOut);


/**
 * Password Callback
 * -----------------
 *  This function is called when the private key file is opened.
 *
 *  NOTE: This is where code should be inserted to get password from user
 *  or whatever hook to the GUI on the groundstation.
 *
 *  @param  buf      Buffer to place the password in.
 *  @param  size     Length, in bytes, of the password.
 *  @param  rwflag   Flag to indicate reading or writing, 0 and 1 respectively.
 *                   e.g. "A typical routine will ask the user to verify the
 *                   passphrase (for example by prompting for it twice) if
 *                   rwflag is 1" (from man page)
 *  @param  u        Parameter passed from data_sign_with_key_file function.
 *
 *  @retval 0        Indicates an error has occured.
 *          else     Should be the size of the buffer.
 */
int pw_cb(char *buf, int size, int rwflag, void *u);

#ifdef __cplusplus
}
#endif


#endif
