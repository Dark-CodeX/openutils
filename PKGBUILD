pkgname="sstring"
pkgver="49.0.1"
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
  "4084915ffaeb9fe17d13f85c486461fa40b26b91a7289c2b3fd4881d933bacfa41f7d96ca62994cc77d9be21a80107f7805db5bd47ff27f36b4247a3219e3a9d"
  "6455da9b74d13e534728a1d1a2387299aa578a2704b73e1deaeb6ae3be8d5bd684cc7f925a0e22cbede10d625c6c5a33b0860f4ccca791a0eb73906c0f9dc45c"
  "f48777d508d19227a9e5f971d21043fa8f1354fbe1d15d3f6b5bf37d0feeb888ccafd5ca8d820b2202004670841e24894e1e6c4b92a76d5eb4b4c168bcb4815d"
  "4798ed169dc9881d09a53ae6095584c7f8e63d6811e98460b400f318001365fea75173fcada66a9b5a23c66ee4652d96ebbafa4bdce62e087e35aa53538c8cb7"
  "e76f12eaa6e207ab32faaaeb1d1d73d9d2c0bc2543b292e59bf9c7f5b729e521bfe1beb3d9d50f694cd54c44d5d1374d413630ab68f4b469f9699af82935f277")

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
