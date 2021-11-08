pkgname="sstring"
pkgver="48.0.0"
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
  "4c5693ae39a769796cfabd12a33301c4dbb8a16428b986c7e6ac547bf64a1dd61d37cafe26c327436eceeeb1bc77eae2ce2943f59b66a2d5ceb412670296ab84"
  "61157be24569ad48c8bc2610135f3fc738620e901018e3aefa315ef1724ab1a58b7c399c62551a06e4d07e1f5b9a555cb07f0e18f1485be114792f9ee61eb5e2"
  "c3b6cd9675eed6bd2dee042bc499e69801a36de85fb51ea9296d9f9d30cf496942d3bdc3b53aebb49c7c66680f2dfa36016dba151455afa5789f07993869824b"
  "feee6715c7e8c1222fad8f3e96046aeef8082ce73d1a980ba34e4a366161e9286fbc9e2ff9652599efb8b94e8126272b0ed706e2f52f9ab5104ad8bc88087855")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
