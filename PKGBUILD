pkgname="sstring"
pkgver="49.1.0"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "562229e39f18a7ccfcc402ddd7b5b48c566546cb3bb63c8ac7d59dbb0b34b0415aacd32602ab888bbd2fedb537f959d44b8f84ea69d785fd4ac96c63d13b9497"
  "ec5558a769e96dc21b87d31465bb4f9043f279aec5efbf88ec44852a077ee4c54f1bb98dc09ea178b85b61ca80ecee5731d02023d5d46c342fc751d51cb27ec8"
  "361d5be5f841adabc9e75f5b2176f700ccffab1cb85aa1408fddb78bc338c5aff64997a8bfe022fa71bc3946157f63e424235f3a024a2491d38e72e1ad7e1de6"
  "0e84be9c07266821b96783e2e2337dc8669f7473d30570ff93691401840fd879aff593372ccb9d4125b082cdcda8701c07b1717fb203005dd9f3a7e98c9881b5"
  "b65d62b242eb9a6a04b04b0dc70d529604b604702c467bed2520770e3d006b4708bb147100bc57d1b46ac4b6f0cd8799d6e2d7f6f4d2822f50cd23be9a6f648c")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
