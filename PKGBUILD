pkgname="sstring"
pkgver="47.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "c35bf1ab1466543ff741f9a32da48d5e3e7c5c6b3f9cf295e0e734c3137f6208f6dacf3248d4aa06075b61ebb9a840bf011cc2d68b4a62af317bcb2fd93bfcb0"
  "a5a05aa7cd7996618a00d18e913b9991a849e832b57f4c96ce9a699cf7b65fcdf80c1852e76688d69bf5a561d8421f0dd52254fa1fb643bb340310202a89d2bf"
  "57d167d905c48c9f1a0ff763e1da14a1e5ef81540221462d68523232e78d7b41d51b120a7c65fd6b63a9fe4dae63697d6eb6a1063855f89f91647d15f691e29f"
  "0528fb4f808beae6945fb6be84b26dc0926ba7b95e030f5f58294030e1e6f6a03c9d7589b06c7b18d6780132e06cc6bc2f6713d61d89cb7d138b90573607dcca")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
