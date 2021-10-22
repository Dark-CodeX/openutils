pkgname="sstring"
pkgver="31.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("34bf6dbd076b2e1d73f8269c1190723cb4692fb77fecd15930a7cb5e2511d8d3ec616d38a1b8e5f879c9d893b74cb70cbe288ec858dfc2a4bf4072d41441f9a3" "773fcaefd89ad8da7d009b2ed0368ad7809ea2339b19e6e11af551e8bfb0609a041bed852079a8a1e86a90546d05643e4065208675ba18a3e5a603c873c8b3fa" "6c1cdbae76bb729b1040d38af7204c974ff323f4d9eeb6176b387a67f42dcd440bd6ce83d0a8f3eabe955f3cedce995d0cc59f010181340137ff726ef125b7f3" "5a04ced93a6dfdb43797116d44fe1924d0e6b034d5a4a361cedadbf8255268183d17790ee3c79d25fb460cf1d2db0308eba184ec50d75d08cea1e17add4fa56c")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
