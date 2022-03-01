pkgname="openutils-sstring"
pkgver="1.6.1"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
  "31bf051a90b61a3ce73f73940e4076b8364ad4613aa3a41e1a597c892129220bbb64c40ab9657b71af3fab95ef37fb933c7cf6c9ac56bf33d418709e3570eb00"
  "fbd166a698e5713284b7cfcdf14e1e9a277674fa04e97a826d111f68171c7338a2d3d829b60cf84e22c04ccb8373daef0cdb07eb94d70ec588eb0b10874e2e7a"
  "778a908a4664bbf42ec4ff0a4822208d1a5c88ef0ecb10da3adbda44ec9f9cbdaefd6ac992173ba5fdeeb80362dc5b014441062e9b0e2a274822e562d8e382b8"
  "6d9a42933cb5a7176fe669eab3a9e0224e7fff0c3f27dd19784a46c76dac63923bd533b36d87c4421235fb3dc8b8dd987a50355e7514b94007e970d122b1afd7"
  "3234b252875f790b3cd7c162df989c55a7d5e2e78ffc2042bc967dc0e4e0db103e9fae567b70d59ba47a10448ead17841d36801249ee9f4570ad725d09a2b0ee")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
  echo "Done!"
}
