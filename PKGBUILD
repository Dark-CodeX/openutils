pkgname="sstring"
pkgver="1.5.0"
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
  "c5d648606fa59e44d90414fd22c79e2ea1b0788299b9f515667e2da9b009b4a515fdfb3c2a8328089ba799f016bc52fccd146c895b619a0d76499afb517eeb6f"
  "c2827cbd11df6836004b3439867e62956ae676888cf9cf3826a06aad823d5178b41bebd684df6923615b359c4cd6a982fa4b5ec24ec215c2a69729be8ab90350"
  "fa4ac665a4434ff5e0423d061a1cf2fe3a84a3b71134741b9e26e040745a08caac3491ea7c7049e59b3b505fe6c145eaae015871170ce2343def1b19eb20ee2c"
  "8aa0fc18397ff19f7cf69e89114eaf2c4178f694be14440a6590630052b607a9bbe7bdcc6d565b3c285490d682ba92758d96e3618ddbed6df4df7d9d67582624"
  "c7e329e6966845b822ad471c295f9365d43dfb24b83d9fc0cfec374785cbf70466885f42c2ace6c0c04451f96eeb3e832d003d4e5ae4dfa7c28167525cbadfed")

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
