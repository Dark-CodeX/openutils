pkgname="sstring"
pkgver="1.5.5"
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
  "8764c8cc0290efe852b98daf9e5131ee35e6510a75c4836bdfea5b46726157a6e6244d50aaf8ddbf24f9fb4fc6f4b39aca03fd6e34b1d8fa9cbe588aabd9965d"
  "6e7f7a8f682e3a197588ccae4e335b5256228eb72f13dfb57f42ffd1203ff2cc7e267d078a2980ba416947a600b43222f3f9fbdbae4541b8346688dd899e62f0"
  "776f090a0be731cf399865dac8bde3f16769bda4ddd6fc33399e0fd6a343270277e716442a3ee2f2613ed80f292ac43d6ff3b2522103fe1166a2c788ef944861"
  "004a6e4e30ef4f35f385edcba49556d9770c64470596135491c0e8c71b6e37656149c8fcb83fa1a2c09eb775c24b48036db80e7d2b0f2827179413fe5c1535fd"
  "ff1164cd3779945867f00fd110aaca73d6d3bdb0c6bf07b3297572896247403d6480acc939e5a7fb795fa3328673af319c02c97128c409e690e3c67981679cd5")

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
