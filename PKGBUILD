pkgname="openutils-sstring"
pkgver="1.5.7"
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
  "7c8e69b597954d377d722c5484b1742e7e27d49b6246267739b9f21031bb0fe4c960412f278e4441fd5bd01883ebb856a63eb9008bce437b6c58e0228ded6187"
  "c1b66fad944f95d352281c5c632b914575450a1316e822ca0d9f3a57d6fd917955789e09589a47720a425b8c700b8b680a20370585004da0a10beac4f3cafff8"
  "71d40a32ca2ea4e955d5dd693f315a0e0fb2fa6b3df4200350345f05305a7abd96efc771981fbb6039f0081ca9554ba2aae94736e93ad3456182b84266ba9f41"
  "27876e96c84e50049c10617b134a7168a0c2b8c2b6852e29c74a1613c9781aa7bf8249d1b8db84f7f817c476ebe7483cdfd279278c777ac840031560fe0a4a29"
  "6e7dff310d65ef839c57ba1e87738f8aa39afe1867aa2c7ed5b7c52326ccfd5c9da2fe3505d835025550299de127274bb6d3e47dda494e7f815f063bfb008068")

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
