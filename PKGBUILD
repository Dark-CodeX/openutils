pkgname="sstring"
pkgver="8.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("8fe4b5df23103da49fa8f5453b15e3ea6f8df112d42143bc60bbfc07906fb6fce9d5db3633f2aae402f701e41bfb02b11f3badf3137dabddbef53a370de60ec0" "f8222cbfccfcde8bd5795d8f7c06f025de72b77134e55ba8772c67490551fa16a1c779320fdcaad3abf343837346df437c1cb1acd96f005b0c45215658dd8566" "5a5638b58e9dfe8617a329f5ab8d06762cab7d98b4d9f9dde74fd37bbb353575eabf4441557b1da23ffc414d6eeafc2b5c2f36694fb5d4fd5f49c1a3ff1aea69")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
