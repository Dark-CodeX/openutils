pkgname="sstring"
pkgver="37.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("8777f1ff1d1e390558f0cf36592db180876ae00c92827686e0271056bf900f29126cc8c588f36f35238649ee1eb29118062dc5781faaaa546d7475c2825a659b" "9e37bc966c2e5baa6c0e0bc584882e157020018b0374de51092a5de5e084513f25bdcc07e1b92d071476aa947d86d2d7236ecda1ff5c4adf8e0b8b0278bcb6f4" "bcc800c6383d03e9bf37984e29fed5663a0676382e6cc47449fe92ef079609c45c194bb2d8421731b2f0d392b1eb2b9e9cca3ec115ce174e9c4be958c6046f77" "b42ddae57abdf199dee2bd23998f8e81e46e8cb62d4d2b843ce63fb65ef33946c884761970cb5c579d4e5284d6141260c8311fdb132180f638b6aeaf4730f089")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
